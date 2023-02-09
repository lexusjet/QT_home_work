#ifndef QLISTMODEL_H
#define QLISTMODEL_H

#include <QAbstractListModel>
#include <QSize>
#include <QBrush>
#include <QFont>
#include <QStringList>
#include "programlanguage.h"

class QListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit QListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const ;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;

    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) ;

    Qt::ItemFlags flags(const QModelIndex& index) const ;

    void populate(QList<ProgramLanguage> *newValues);

    void append(ProgramLanguage value);

    void delete_row(int idx);

    void insertAt(int idx, ProgramLanguage value);
private:
    QList <ProgramLanguage> values;

public slots:

};

#endif // QLISTMODEL_H
