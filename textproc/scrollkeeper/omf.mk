# $NetBSD: omf.mk,v 1.9 2005/12/05 20:51:08 rillig Exp $
#
# This Makefile fragment is intended to be included by packages that install
# OMF files.  It takes care of registering them in scrollkeeper's global
# database.
#
# The following variables are automatically defined for free use in packages:
#    SCROLLKEEPER_DATADIR   - scrollkeeper's data directory.
#    SCROLLKEEPER_REBUILDDB - scrollkeeper-rebuilddb binary program.
#    SCROLLKEEPER_UPDATEDB  - scrollkeeper-update binary program.
#

.if !defined(SCROLLKEEPER_OMF_MK)
SCROLLKEEPER_OMF_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# scrollkeeper's data directory.
SCROLLKEEPER_DATADIR=	${BUILDLINK_PREFIX.scrollkeeper}/libdata/scrollkeeper

# scrollkeeper binary programs.
SCROLLKEEPER_REBUILDDB=	${BUILDLINK_PREFIX.scrollkeeper}/bin/scrollkeeper-rebuilddb
SCROLLKEEPER_UPDATEDB=	${BUILDLINK_PREFIX.scrollkeeper}/bin/scrollkeeper-update

USE_PKGINSTALL=		YES
INSTALL_EXTRA_TMPL+=	${.CURDIR}/../../textproc/scrollkeeper/files/install.tmpl
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/../../textproc/scrollkeeper/files/install.tmpl

FILES_SUBST+=		SCROLLKEEPER_DATADIR=${SCROLLKEEPER_DATADIR:Q}
FILES_SUBST+=		SCROLLKEEPER_REBUILDDB=${SCROLLKEEPER_REBUILDDB:Q}
FILES_SUBST+=		SCROLLKEEPER_UPDATEDB=${SCROLLKEEPER_UPDATEDB:Q}

PRINT_PLIST_AWK+=	/^libdata\/scrollkeeper/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm libdata\/scrollkeeper/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/omf$$/ \
				{ print "@comment in scrollkeeper: " $$0; \
				  next; }

.include "../../textproc/scrollkeeper/buildlink3.mk"

.endif	# SCROLLKEEPER_OMF_MK
