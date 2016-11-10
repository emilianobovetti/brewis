open Config_file

let pwd = Filename.current_dir_name
let file_name = Filename.concat pwd "brewis.conf"

let required = new group
let optional = new group

let bluetooth_address    = new string_cp ~group:required ["bluetooth_address"]    ""           ""
let bluetooth_channel    = new int_cp    ~group:required ["bluetooth_channel"]    1            ""
let base_url             = new string_cp ~group:required ["base_url"]             ""           ""
let auth_name            = new string_cp ~group:required ["auth_name"]            ""           ""
let auth_password        = new string_cp ~group:required ["auth_password"]        ""           ""

let working_directory    = new string_cp ~group:optional ["working_directory"]    pwd          ""
let daemon_pidfile       = new string_cp ~group:optional ["daemon_pidfile"]       "brewis.pid" ""
let daemon_logfile       = new string_cp ~group:optional ["daemon_logfile"]       "brewis.log" ""
let jwt_refresh_interval = new int_cp    ~group:optional ["jwt_refresh_interval"] 1800         ""
let message_terminator   = new string_cp ~group:optional ["message_terminator"]   "\r\n"       ""
let debugging_mode       = new bool_cp   ~group:optional ["debugging_mode"]       false        ""

let () = required#read ~no_default:true file_name
let () = optional#read ~no_default:false file_name

let bluetooth_address    = bluetooth_address#get
let bluetooth_channel    = bluetooth_channel#get
let base_url             = base_url#get
let auth_name            = auth_name#get
let auth_password        = auth_password#get

let working_directory    = working_directory#get
let daemon_pidfile       = Filename.concat working_directory daemon_pidfile#get
let daemon_logfile       = Filename.concat working_directory daemon_logfile#get
let jwt_refresh_interval = Core.Span.create ~sec:jwt_refresh_interval#get ()
let message_terminator   = message_terminator#get
let debugging_mode       = debugging_mode#get
