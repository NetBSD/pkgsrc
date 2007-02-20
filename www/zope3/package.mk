# $NetBSD: package.mk,v 1.4 2007/02/20 17:30:18 he Exp $
#

DEPENDS+=		zope3>=3.3.1:../../www/zope3

.include "Makefile.common"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${ZOPE3_DIR} \
			--force

BUILD_TARGET=		build
