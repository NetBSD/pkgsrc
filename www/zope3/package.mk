# $NetBSD: package.mk,v 1.1 2006/01/07 13:13:28 wiz Exp $
#

DEPENDS+=		zope3>=3.2.0:../../www/zope3

.include "Makefile.common"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${ZOPE3_DIR} \
			--force

BUILD_TARGET=		build
