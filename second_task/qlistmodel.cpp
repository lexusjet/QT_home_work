#include "qlistmodel.h"

QListModel::QListModel(QObject *parent)
    :QAbstractListModel(parent){}

int QListModel::rowCount(const QModelIndex &parent) const
{
    return values.count();
}


QVariant QListModel::data(const QModelIndex &index, int role) const
{
    QVariant value;

    if(!index.isValid()) return value;

        switch ( role )
        {
            case Qt::DisplayRole: //string
            {
                value = values.at(index.row()).get_name();
            }
            break;

            case Qt::DecorationRole: //data
            {
                value = QPixmap(":res/icons/" + values.value(index.row()).get_icon());
            }
            break;

            default:
                break;
        }
    return value;

}

bool QListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role != Qt::EditRole) return false;
    QString text = value.toString();
    ProgramLanguage n(text, "default.png");
    values.replace(index.row(), n);
}


Qt::ItemFlags QListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;

}

void QListModel::populate(QList<ProgramLanguage> *newValues)
{
    values.append(*newValues);
}

void QListModel::append(ProgramLanguage value)
{
    values.append(value);
}

void QListModel::delete_row(int idx)
{
    if(idx < values.size()) values.removeAt(idx);
}

void QListModel::insertAt(int idx, ProgramLanguage value)
{
    values.insert(idx, value);
}
