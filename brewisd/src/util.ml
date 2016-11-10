
module String = struct
    external unsafe_get : string -> int -> char = "%string_unsafe_get"

    (*TODO tests*)
    let contains_from_to str start len sub =
        let str_len = String.length str
        and sub_len = String.length sub
        and stop = start + len in

        if sub_len = 0 then
            true
        else if sub_len > str_len then
            false
        else if start < 0 then
            raise (Invalid_argument "contains_from_to start index < 0")
        else if start >= str_len then
            raise (Invalid_argument "contains_from_to start index >= str_len")
        else if len < sub_len then
            raise (Invalid_argument "contains_from_to len < sub_len")
        else if stop > str_len then
            raise (Invalid_argument "contains_from_to len out of bounds")
        else

        let rec str_loop str_idx =
            str_idx + sub_len <= stop && (sub_loop str_idx 0 true || str_loop (str_idx + 1))
        and sub_loop str_idx sub_idx acc =
            if sub_idx < sub_len then
                let char_equal = unsafe_get str (str_idx + sub_idx) = unsafe_get sub sub_idx in
                acc && sub_loop str_idx (sub_idx + 1) char_equal
            else
                acc
        in
        str_loop start

    let contains_from str start sub =
        contains_from_to str start (String.length str - start) sub

    let contains str sub =
        contains_from_to str 0 (String.length str) sub

    let starts_with str sub =
        contains_from_to str 0 (String.length sub) sub

    let from str idx =
        String.sub str idx (String.length str - idx)
end
