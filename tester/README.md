# Кориштење

За имена фајлова, укључијући и имена и распоред тест фајлова види:
[https://github.com/novakpetrovic/takmicenje](https://github.com/novakpetrovic/takmicenje)

Ако, на примјер, радимо на рјешењу **005-2017-005-05.cpp** кориштење тестера је сљедеће:

* Припремити све тест фајлове (улазе и рјешења) у директорији **005-2017-005-05/tests**
  * Избјегавати користити празну линију као посљедњи ред у улазним (.in.txt), излазним (.out.txt), и фајловима са рјешењима (.sol.txt).
* Дефинисати фајл `./test.sh` и користити га за тестирање.

# Јунит тестинг фрејмворк

Јунит тестинг фрејмворк (Unit Testing Framework) коју користимо је Кеч (Catch): [https://github.com/philsquared/Catch](https://github.com/philsquared/Catch).

Catch is a modern, C++-native, header-only, test framework for unit-tests, TDD and BDD - using C++98, C++03, C++11, C++14 and later.
