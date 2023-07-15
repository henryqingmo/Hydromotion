#ifndef DEBUG_H
#define DEBUG_H
#include <QDebug>

QTextStream& qStdOut()
{
    static QTextStream ts( stdout );
    return ts;
}

#endif // DEBUG_H
