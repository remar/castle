#ifndef COEPLUGIN_H
#define COEPLUGIN_H

#include "coe_global.h"

#include "mapwriterinterface.h"
#include "mapreaderinterface.h"

#include <QObject>

namespace Coe {

  class COESHARED_EXPORT CoePlugin : public QObject, 
    public Tiled::MapWriterInterface, public Tiled::MapReaderInterface
{
    Q_OBJECT
      Q_INTERFACES(Tiled::MapWriterInterface Tiled::MapReaderInterface)

public:
    CoePlugin();

    Tiled::Map *read(const QString &fileName);
    bool write(const Tiled::Map *map, const QString &fileName);
    QString nameFilter() const;
    QString errorString() const;
    bool supportsFile(const QString &fileName) const;

private:
    QString makeAbsolute(const QString &path);

    QString mError;
    QString mPath;
};

} // namespace Coe

#endif // COEPLUGIN_H
