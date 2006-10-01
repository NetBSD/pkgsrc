# $NetBSD: package.mk,v 1.3 2006/10/01 14:25:23 taca Exp $
#

DEPENDS+=		zope3>=3.3.0:../../www/zope3

.include "Makefile.common"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${ZOPE3_DIR} \
			--force

BUILD_TARGET=		build
