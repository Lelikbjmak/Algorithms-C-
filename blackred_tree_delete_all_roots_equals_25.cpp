#include<iostream>
#include<Windows.h>
#include<string>
#include<iomanip>
#include<clocale>




using namespace std;



// Удалить все узлы со значением 25




struct Tree // Узел
{

    int info;   // Информационная часть

    Tree* left = nullptr;  // Адресная часть

    Tree* right = nullptr;        // Адресная часть

    int depth = 1;                // Глубина поддерева

}*root;




void obr_view(Tree* );
void simm_view(Tree*);
void simple_view(Tree*);
int dph(const Tree*);             // Глубина поддерева
int bfactor(const Tree*);         // Вычисление разбалансированности
Tree* rotateright(Tree*);         // правый поворот вокруг p
Tree* rotateleft(Tree*);          // левый поворот вокруг q
Tree* AVL(Tree*);                 // балансировка узла p
Tree* push(Tree*, int);           // Добавление нового элемента
Tree* find_min(Tree*);            // Поиск узла с минимальным ключом
Tree* find_max(Tree*);            // Поиск узла с max ключом
Tree* pop(Tree*, int);            // Удаление узла с ключом k
Tree* search(Tree*, int);         // Поиск по ключу
Tree* pop(Tree*);                 // Удаление всего дерева
bool empty(Tree* p);              // Проверка наличия элементов в дереве




int dph(const Tree* p)             // Глубина поддерева

{

    if (!p) return 0;              // Если поддерево отсутствует  (p == nullptr)

    return p->depth;

}






int bfactor(const Tree* p) // Вычисление разбалансированности

{

    return dph(p->right) - dph(p->left);

}




void maxdepth(Tree* p)  // Вычисление глубины поддерева

{

    int l = dph(p->left);

    int r = dph(p->right);

    if (l > r) p->depth = l + 1;

    else p->depth = r + 1;

}





Tree* rotateright(Tree* root)     // правый поворот вокруг p
{

    Tree* p = root->left;

    root->left = p->right;

    p->right = root;

    maxdepth(root);

    maxdepth(p);

    return p;

}



Tree* rotateleft(Tree* root) // левый поворот вокруг q

{

    Tree* p = root->right;

    root->right = p->left;

    p->left = root;

    maxdepth(root);

    maxdepth(p);

    return p;

}



Tree* AVL(Tree* p) // балансировка узла p

{

    maxdepth(p); // Вычисление глубины поддерева

    if (bfactor(p) == 2)  // Если

    {

        if (bfactor(p->right) < 0)        p->right = rotateright(p->right);

        return rotateleft(p);

    }

    if (bfactor(p) == -2)

    {

        if (bfactor(p->left) > 0)           p->left = rotateleft(p->left);

        return rotateright(p);

    }

    return p; // балансировка не нужна

}



Tree* push(Tree* p, int key) // Добавление нового элемента

{

    if (!p) {

        p = new Tree;

        p->info = key;

        return p;

    }

    if (key < p->info) p->left = push(p->left, key);

    else p->right = push(p->right, key);

    return AVL(p);

}



Tree* find_max(Tree* p)  // Поиск узла с max ключом

{

    Tree* q = p;

    while (q->right != nullptr) q = q->right;

    return q;

}



Tree* find_min(Tree* p) // Поиск узла с минимальным ключом

{

    Tree* q = p;

    while (q->left != nullptr) q = q->left;

    return q;

}





Tree* removemin(Tree* p) // Отключение узла с максимальным ключом из поддерева

{

    if (!p->right) return p->left;

    p->right = removemin(p->right);

    return AVL(p);

}



Tree* pop(Tree* p, int key) // Удаление узла с ключом k

{

    if (!p) return nullptr;  // Ключ не обнаружен

    if (key < p->info) p->left = pop(p->left, key);

    else

        if (key > p->info) p->right = pop(p->right, key);

        else // Ключ найден

        {

            Tree* q = p->left;

            Tree* r = p->right;

            delete p;

            if (!r) return q;

            Tree* rep = find_max(q);

            rep->left = removemin(q);

            rep->right = r;

            return AVL(rep);

        }

    return AVL(p);

}



Tree* pop(Tree* p) // Удаление всего дерева

{

    if (!p) 
        return nullptr;
    else
    {
        pop(p->left);

        pop(p->right);

        delete(p);
    }

    return nullptr;
}



Tree* search(Tree* p, int key) // Поиск по ключу

{

    Tree* q = p;

    while (q)

    {

        if (q->info == key) return q;

        if (key < q->info) q = q->left;

        else q = q->right;

    }

    return q;

}




bool empty(Tree* p)   // Проверка наличия элементов в дереве
{  

    if (p) return false;

    else return true;

}





void view_tree(Tree* p, int r = 0)  // Вывод дерева на экран
{

    if (!p) return;

    
    cout << setiosflags(ios::right);

    view_tree(p->right, r + 5);

    cout << setw(r) << p->info << endl;

    view_tree(p->left, r + 5);

}




int menu()
{
    
    cout << "Выберите обход дерева: " << endl;
    cout << "1. Прямой " << endl;
    cout << "2. Обратный " << endl;
    cout << "3. Симметричный " << endl;
    cout << "4. Выход " << endl;

    int as;

    bool lp = true;

    while (lp)
    {
        cin >> as;

        if (cin.get() == (int)'\n' && (as >= 1 && as <= 4))
            lp = false;

        else
        {
            cout << "Неверная операция! Повторите попытку! " << endl;
            fflush(stdin);
        }

    }


    switch (as)
    {

    case 1: {view_tree(root); cout << "\n";  simple_view(root); break; }
    case 2: {view_tree(root); cout << "\n";; obr_view(root); break; }
    case 3:{view_tree(root); cout << "\n";; simm_view(root); break;}
    case 4: return 0;
    default: cout << "Выебрите корректно! " << endl;

    }
    
    cout << "\nЖелаете посмотреть еще?(1 да/2 нет) " << endl;

    int ass;

    cin >> ass;

    switch (ass)
    {
    case 1:system("cls"); menu(); break;
    case 2: return 0;
    }
   
    return 10;
}




void simm_view(Tree* root)
{
    if (root == nullptr)
        return;

     simm_view(root->left);

    cout << root->info<<"  ";

    simm_view(root->right);

    

}






void obr_view(Tree* root)
{
    if (root == nullptr)
        return;

    simm_view(root->left);
      
    cout << root->info<<"  ";

    simm_view(root->right);

}





void simple_view(Tree* root)
{
    if (root == nullptr)
        return;


    cout << root->info << "  ";

    simple_view(root->left);
    simple_view(root->right);



}





int main()
{

    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);       // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    setlocale(LC_ALL, "ru");  // подключение русского языка 


    root = nullptr;   // Указатель на корень дерева
    
    int count;
    cout << "Введите количество узлов дерева ";
    cin >> count;


    int* elements = new int[count];   // Массив состоящий из элементов дерева


    cout << "Значения узлов дерева: " << endl;

    for (int i = 0; i < count; i++)
    {
        cin >> elements[i];
        //cout << "[" << i << "]) ";        // Заполнение дерева
        root = push(root, elements[i]);

    }

    cout << "Дерево:\n\n";

    view_tree(root);  // Выводит дерево

    cout << "\n\n";


    int keyy;
    cout << "Введите какое значение корня удалить: " << endl;
    cin >> keyy;
   


    for (int i = 0; i < count; i++)
      root = pop(root, keyy);
    
    
   
        cout << "Дерево после удаления: \n\n" << endl;

        view_tree(root);

        cout << "\n\nПоиск элемента с заданным ключом - " << keyy << endl;

        Tree* q = search(root, keyy); // Поиск элемента с введенным ключом

        if(q == nullptr)
            cout<<"Элемент "<<keyy<<" отсутствует в дереве! "<<endl;

        cout << "\n\n";

        menu();


        root = pop(root); // Удаление дерева

        if (empty(root)) 
            cout << "Дерево удалено! ";
        else  
            cout << "Неполное удаление! ";


        return 0;

}