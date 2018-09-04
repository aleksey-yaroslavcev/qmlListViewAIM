#include "TestModel.h"
#include <QDebug>

TestModel::TestModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int TestModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return _list.size();
}

QVariant TestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() && role!=TextRole)
        return QVariant();


    return QVariant(_list.at(index.row()));
}

bool TestModel::insertRows(int row, int count, const QModelIndex &parent)
{
    qDebug()<<"insert: 1";
    beginInsertRows(parent, row, row + count - 1);
    qDebug()<<"insert: 2";
    _list.insert(row,QString("Row %1").arg(row));
    qDebug()<<"insert: 3";
    endInsertRows();
    qDebug()<<"insert: 4";
    return true;
}

bool TestModel::removeRows(int row, int count, const QModelIndex &parent)
{
    qDebug()<<"remove: 1";
    beginRemoveRows(parent, row, row + count - 1);
    qDebug()<<"remove: 2";
    _list.removeAt(row);
    qDebug()<<"remove: 3";
    endRemoveRows();
    qDebug()<<"remove: 4";
    return true;
}

void TestModel::addNew()
{
    insertRows(rowCount(),1,QModelIndex());
}

void TestModel::removeLast()
{
    if (rowCount())
        removeRows(rowCount()-1,1,QModelIndex());
}

QHash<int, QByteArray> TestModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TextRole] = "TextRole";
    return roles;
}
