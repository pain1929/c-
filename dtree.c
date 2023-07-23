#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _NODE
{
    struct _NODE *children[26];
    char end;

} NODE, *PNODE;

// 节点没有显式的value 节点的value由父节点表示
// 节点的值是父节点children数组中对应的下标
static PNODE root = NULL;

PNODE create()
{
    PNODE node = (PNODE)malloc(sizeof(NODE));

    int i = 0;
    for (i = 0; i < 26; i++)
    {
        node->children[i] = NULL;
    }
    node->end = 0;

    return node;
}

void _delete(PNODE node)
{
    int i = 0;
    for (i = 0; i < 26; i++)
    {
        PNODE temp = node->children[i];
        if(temp!=NULL)
        {
            _delete(temp);
        }
    }
    free(node);
    
}

void delete()
{
    _delete(root);
}

void init()
{
    if (root == NULL)
    {
        root = create();
    }
}

void put(const char *str, int index, PNODE node)
{
    size_t len = strlen(str);
    if (index >= len)
        return;

    size_t arr_index = str[index] - 'a';
    if (node->children[arr_index] == NULL) // 为空 直接添加
    {
        PNODE new_node = create();

        if (index == len - 1)
            new_node->end = 1;

        node->children[arr_index] = new_node;
        put(str, index + 1, new_node);
    }
    else // 不为空 往下递归
    {
        if (index == len - 1)
        {
            node->children[arr_index]->end = 1;
        }
        else
        {
            put(str, index + 1, node->children[arr_index]);
        }
    }
}

void put_str(const char *str)
{
    put(str, 0, root);
}

void for_each(PNODE node, char *buffer, int deep)
{
    if (node == NULL)
        return;

    // 遍历 26个子节点
    int i = 0;
    for (i = 0; i < 26; i++)
    {
        PNODE temp = node->children[i];

        if (temp != NULL)
        {
            buffer[deep] = 'a' + i;

            if (temp->end)
            {
                buffer[deep + 1] = '\0';
                printf("%s\n", buffer);
            }

            for_each(temp, buffer, deep + 1);
        }
    }
}

void for_each_str()
{
    char buffer[128] = "";
    for_each(root, buffer, 0);
}

void find(PNODE node, const char *str, int index, char *buffer)
{
    if (node == NULL)
        return;

    size_t len = strlen(str);
    if (index < len)
    {
        int arr_index = str[index] - 'a';
        PNODE temp = node->children[arr_index];

        if (temp != NULL)
        {
            buffer[index] = str[index];
            if (temp->end)
            {
                buffer[index + 1] = '\0';
                printf("%s\n", buffer);
            }
            find(temp, str, index + 1, buffer);
        }
    }
    else
    {
        int i = 0;
        for (i = 0; i < 26; i++)
        {
            PNODE temp = node->children[i];
            if (temp != NULL)
            {
                buffer[index] = 'a' + i;
                if (temp->end)
                {
                    buffer[index + 1] = '\0';
                    printf("%s\n", buffer);
                }
                find(temp, str, index + 1, buffer);
            }
        }
    }
}

void find_str(const char *str)
{
    char buffer[128] = "";
    find(root, str, 0, buffer);
}

int main(int argc, char const *argv[])
{
    init();
    put_str("ab");
    put_str("ac");
    put_str("helloworld");
    put_str("helloworlda");
    put_str("abcdef");
    return 0;
}
