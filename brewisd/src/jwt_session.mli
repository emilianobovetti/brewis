open Async
open Cohttp_async

type t

(*
 * create url credentials
 *
 * e.g.
 * create "http://localhost/my/jwt/service/"
 * [ "name", "auth name"
 * ; "password", "auth password"
 * ]
 *
 * Return session
 *)
val create : string -> (string * string) list -> t

(*
 * get route session
 *)
val get :
    ?headers:Cohttp.Header.t ->
    t -> string -> (Response.t * Body.t) Deferred.t

(*
 * post ?(body=`Null) route session
 *)
val post :
    ?headers:Cohttp.Header.t ->
    ?body:Yojson.t ->
    t -> string -> (Response.t * Body.t) Deferred.t

(*
 * authenticate route session
 *)
val authenticate : t -> string -> [ `Ok of t | `Error of string ] Deferred.t

(*
 * refresh route session
 *)
val refresh : t -> string -> [ `Ok of t | `Error of string ] Deferred.t
