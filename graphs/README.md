### Графи

1. По даден ориентиран непретеглен граф (представен чрез списък на наследниците):
     * да се провери има ли примки в графа
     * да се провери дали графът е пълен (всеки връх е свързан с всички останали)
     * да се провери дали графът всъщност е неориентиран (т.е. има ребро между А и Б тогава и само тогава, когато има ребро между Б и А)
     * да се построи граф, допълнение на дадения (т.е. ако даденият граф е G(V,E⊆VxV), резултатът е G1 (V,E1 ={(x,y) | x, y ∈ V,(x,y) ∉ E})

2. Имаме група от N човека. Всеки човек има 0 или повече най-добри приятели, с които споделя всичките си тайни (възможно е А да е най-добър приятел на Б, но Б да не е на А). Когато човек научи нечия тайна, веднага я споделя със своите най-добри приятели.

   По даден човек Х, споделил тайната си със своите приятели, да се намери:
     * колко души ще узнаят тайната на Х
     * кой ще чуе тайната на Х от най-много различни хора

   *Упътване*: имаме ориентиран граф без примки, в който тайните се разпространяват по метода на вълната