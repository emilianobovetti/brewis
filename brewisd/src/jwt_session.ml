open Async
open Cohttp_async

type t =
    { base_url:    string;
      credentials: (string * string) list;
      token:       string option;
    }

let json_header = ("Content-Type", "application/json")

let empty_header = Cohttp.Header.init ()

let request_headers { token; _ } headers =
    let k, v = json_header in
    let headers' = Cohttp.Header.add headers k v in
    match token with
        | None -> headers'
        | Some t ->
            Cohttp.Header.add headers' "Authorization" ("Bearer " ^ t)

let request_uri { base_url; _ } route =
    base_url ^ route |> Uri.of_string

let credentials_to_json { credentials; _ } =
    `Assoc (List.map (fun (key, value) -> key, `String value) credentials)

let create base_url credentials =
    { base_url; credentials; token = None; }

let get ?(headers=empty_header) session route =
    let headers = request_headers session headers in
    request_uri session route
    |> Client.get ~headers

let post ?(headers=empty_header) ?(body=`Null) session route =
    let headers = request_headers session headers
    and body = body |> Yojson.to_string |> Body.of_string in
    request_uri session route
    |> Client.post ~headers ~body

let authenticate session route =
    post ~body:(credentials_to_json session) session route
    >>= fun (_response, body) ->
    Body.to_string body
    >>| fun body ->
    let open Yojson in let open Basic in
    let json = try from_string body with Json_error _ -> `Assoc [] in
    match Util.member "token" json with
    | `String t -> `Ok { session with token = Some t }
    | _ -> `Error ("Authentication failed: " ^ body)

let refresh session route =
    get session route
    >>| fun (response, _body) ->
    let headers = Response.headers response
    and bearer = "Bearer " in
    match Cohttp.Header.get headers "Authorization" with
    | Some auth when Util.String.starts_with auth bearer ->
        let t = String.length bearer |> Util.String.from auth in
        `Ok { session with token = Some t }
    | _ ->
        `Error "Unable to refresh session, no token received"
