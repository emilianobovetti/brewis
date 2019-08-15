
module String : sig
    val contains : string -> string -> bool
    val contains_from : string -> int -> string -> bool
    val contains_from_to : string -> int -> int -> string -> bool
    val starts_with : string -> string -> bool
    val from : string -> int -> string
end
