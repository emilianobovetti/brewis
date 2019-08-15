open Config_file

let def_conf_file = Filename.concat "/etc" "brewisd.conf"
let env_conf_file = Sys.getenv_opt "BREWISD_CONF"

let arg_conf_file = ref None
let arg_debug = ref false
let arg_stdout = ref false

let parse_anonymous_arg arg =
    failwith ("Unknown arg: " ^ arg)

let speclist = [
    "--conf", Arg.String (fun s -> arg_conf_file := Some s), "Sets config file path";
    "--debug", Arg.Set arg_debug, "Enables debug mode";
    "--stdout", Arg.Set arg_stdout, "Logs on stdout in place of logfile"
]

let () = Arg.parse speclist parse_anonymous_arg "Usage:"

let file_name =
    match !arg_conf_file, env_conf_file, def_conf_file with
    | Some str, _, _
    | None, Some str, _
    | None, None, str ->
        if Sys.file_exists str then
            str
        else
            failwith ("Config file '" ^ str ^ "' not found")

let required = new group
let optional = new group

let bluetooth_address    = new string_cp ~group:required ["bluetooth_address"] "" ""
let bluetooth_channel    = new int_cp    ~group:required ["bluetooth_channel"] 1  ""
let base_url             = new string_cp ~group:required ["base_url"]          "" ""
let auth_name            = new string_cp ~group:required ["auth_name"]         "" ""
let auth_password        = new string_cp ~group:required ["auth_password"]     "" ""

let pidfile              = new string_cp ~group:optional ["pidfile"]     "/var/run/brewisd.pid"  ""
let logfile              = new string_cp ~group:optional ["logfile"]     "/var/log/brewisd.log"  ""
let jwt_refresh_interval = new int_cp    ~group:optional ["jwt_refresh_interval"] 1800           ""
let message_terminator   = new string_cp ~group:optional ["message_terminator"]   "\r\n"         ""
let debug_mode           = new bool_cp   ~group:optional ["debug_mode"]           false          ""

let () = required#read ~no_default:true file_name
let () = optional#read ~no_default:false file_name

let bluetooth_address    = bluetooth_address#get
let bluetooth_channel    = bluetooth_channel#get
let base_url             = base_url#get
let auth_name            = auth_name#get
let auth_password        = auth_password#get

let pidfile              = pidfile#get
let logfile              = logfile#get
let jwt_refresh_interval = Core.Time.Span.create ~sec:jwt_refresh_interval#get ()
let message_terminator   = message_terminator#get
let stdout_mode          = !arg_stdout
let debug_mode           = !arg_debug || debug_mode#get

let () = begin
    if Filename.is_relative pidfile then
        failwith ("Invalid relative path for pidfile '" ^ pidfile ^ "'");

    if Filename.is_relative logfile then
        failwith ("Invalid relative path for logfile '" ^ logfile ^ "'");
end
