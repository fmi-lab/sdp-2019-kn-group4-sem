### HashMap (std::unordered_map)

Задача 1. Към [имплементацията на LinkedHash от лекции](https://github.com/triffon/sdp-2019-20/blob/master/dictionary/linked_hash.cpp) да се добави метод `double efficacy() const`, който пресмята колко ефикасно са разпределени елементите в хеш таблицата (т.е. колко чести са колизиите). Ефикасност на речник със затворено адресиране се пресмята като `(all - colliding) / all`; Стойност 1 означава никакви колизии, а стойност 0 означава крайния случай, в който всички елементи попадат в един бъкет.

Задача 1. Да се създадат няколко LinkedHash<std::string, std::string> обекта, използващи различни хеширащи функции:
  * `constHash`, която за всеки низ връща стойност 5
  * `lenHash`, която за всеки низ връща дължината му
  * `sumASCIIHash`, която събира ascii кодовете на символите в низа
  * `polinomeHash`, който пресмята хеш за низа a<sub>1</sub>a<sub>2</sub>...a<sub>n</sub> по формулата a<sub>1</sub> + a<sub>2</sub>*p + a<sub>3</sub> * p<sup>2</sup> + ... + a<sub>n</sub> * p<sup>n-1</sup>, където p е някое просто число (например 31).
  
  Да се добавят във всеки от тези речници едни и същи 1000 произволни низа и да се сравнят коефициентите им на ефикасност. Използвайте например първите 1000 реда в https://github.com/first20hours/google-10000-english/blob/master/google-10000-english-usa-no-swears.txt
  
  Вижте https://stackoverflow.com/a/1147232 за сравнително кратко обяснение за избора на просто число в последната примерна хешираща функция.

### Spam Filter
Да се имплементира прост спам филтър, който проверява дали дадено съобщение прилича достатъчно на някое от вече отбелязани като спам други съобщения (корпус от спам текстове).

За целта:
  1. Да се дефинира клас SpamFilter с член-данна корпус от текстове на спам съобщения (може да бъде вектор от низове).
  1. Да се напише член-функция, която по зададен текстов файл намира броя срещания за всяка дума от файла (term frequency)
  1. Да се напише член-функция, която пресмята [inverse document frequency](https://en.wikipedia.org/wiki/Tf%E2%80%93idf#Inverse_document_frequency_2) за всяка от думите в корпуса
  1. Да се напише член-функция, която по даден нов текст пресмята [tf-idf](https://en.wikipedia.org/wiki/Tf%E2%80%93idf) стойностите за всяка от думите в документа спрямо корпуса
  1. Да се напише функция, която намира [cosine similarity](https://en.wikipedia.org/wiki/Cosine_similarity#Definition) между два n-мерни вектора
  1. Да се напише член-функция, която по даден текст намира tf-idf представянето му спрямо корпуса спам съобщения и пресмята cosine similarity между дадения текст и всеки от текстовете в корпуса. Ако близостта е по-голяма от зададена граница, текстът да се класифицира като спам