# SILKOM_GUI
Projet MFC d'affichage d'une liste aléatoire de ville dans une fenêtre de dialogue

-Ce projet a été developpé avec Visual Studio Comunity 2022 (17.11.5).
-La solution du projet se trouve dans le repertoire : PROJETS/SilkhomGUI
-L'executable est généré à l'emplacement : PROJETS/LIVRAISON/MyMFC.exe (Fenetre de dialogue)
-La DLL est généré à l'emplacement : PROJETS/LIVRAISON/MyDLL.dll (dll de retour aléatoire de liste de ville).
-La documentation du projet est sous format html et se trouve  à l'emplacement : DOC.zip
-La compilation de l'éxecutable est lié a celle de la dll.

Voici le cahier des charges auquel repond cette application :


    Test MFC

    Nom de la solution : "<votre nom> - MFC" sur le bureau

    La solution sera constitué de 2 projets :
    1) GUI, un projet MFC qui contient une CDialog et une combo box
    2) DLL, un projet DLL qui contient une classe qui retourne une liste/tableau/autre de CString triée de manière aléatoire.

    Voici la liste des chaines codées en "dur" :
    Lyon
    Marseille
    St Etienne
    Orange
    Orléans
    Strasbourg

    Le projet doit être en UNICODE

    Au final, le projet GUI doit instancier la classe du projet DLL et utiliser les chaines pour remplir la combo box.

