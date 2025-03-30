function solution(my_string, overwrite_string, s) {
    var answer = '';
    start = my_string.substring(0, s);
    end = my_string.substring(s + overwrite_string.length);
    answer = start + overwrite_string + end;
    return answer;
}