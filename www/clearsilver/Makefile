# $NetBSD: Makefile,v 1.7 2004/11/29 00:08:57 epg Exp $

.include "Makefile.common"

DEPENDS+=${CLEARSILVER_BASE}{,nb[0-9]*}:../../www/clearsilver-base
DEPENDS+=${PYPKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/py-clearsilver
DEPENDS+=${RUBY_PKGPREFIX}-${DISTNAME}{,nb[0-9]*}:../../www/ruby-clearsilver

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_BUILDLINK=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
NO_MTREE=	YES

.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/rubyversion.mk"

# The NO_PATCH macro is gone so we have to do this to prevent the
# patches from being applied:
do-patch:

do-install:

.include "../../mk/bsd.pkg.mk"
