#include "abstractmapper.h"

std::shared_ptr<sqlite3> fakeDb;
database AbstractMapper::universal_db(fakeDb);

AbstractMapper::AbstractMapper(database _db):db(_db)
{

}
