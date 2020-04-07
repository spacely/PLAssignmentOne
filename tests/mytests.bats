load harness

@test "mytests-1" {
  check '2 - 3 ^ 4' '-79'
}

@test "mytests-2" {
  check '-2 ^ 3 - -4 + 6 - 7 * 7' '39'
}

@test "mytests-3" {
  check '3 - 8 - 9 - 10' '-6'
}

@test "mytests-4" {
  check '5 - 6 ^ 2' '-31'
}

@test "mytests-5" {
  check '500 * 8 - 6 - 4 + -2' '3996'
}

@test "mytests-6" {
  check '-10 - 4 ^ 3 * 6 + 8' '-402'
}

@test "mytests-7" {
  check '100 - -100 ^ 0' '99'
}

@test "mytests-8" {
  check '8 ^ 2 - 1' '63'
}

@test "mytests-9" {
  check '2 ^ 4 - 2' '14'
}

@test "mytests-10" {
  check '-1 + -1 - 8' '-10'
}
