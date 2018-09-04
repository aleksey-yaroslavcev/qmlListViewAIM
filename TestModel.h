#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QAbstractListModel>

class TestModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum ModelRoles {
        TextRole = Qt::UserRole + 1
    };

    explicit TestModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

public slots:
    void addNew();
    void removeLast();

private:
    QList<QString> _list;

    // QAbstractItemModel interface
public:
    virtual QHash<int, QByteArray> roleNames() const override;
};

#endif // TESTMODEL_H
