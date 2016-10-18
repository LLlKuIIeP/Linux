# Ошибки, утилиты, команды Linux

В boot разделе мало места.
</br>1) Удалить образы старых ядер:
```
dpkg -l|grep linux-image //список образов
aptitude remove linux-image<версия ядра> //удаление ядра
aptitude purge linux-image<версия ядра> //удаление ядра из конфига
```


