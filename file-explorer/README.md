### Преговор - файлове, std::string, std::vector. Въведение в std::stack

Да се напише програма - file explorer, поддържаща следните команди:

  * open file: прочита път към текстов файл от клавиатурата и отпечатва първите 10 реда от него;
  * more: Отпечатва следващите 10 реда от текущия отворен файл. При достигане край на файла, отпечатва EOF;
  * go back: Отваря отначало предишния отворен файл, ако има такъв
  * go forward: След команда go back, отива до началния файл (подобно на стандартните back / forward при навигация в историята на браузера)
  
Бонус: при go back / go forward вместо да се показват първите редове на стария файл, да се показват редовете, които потребителят последно е прочел.