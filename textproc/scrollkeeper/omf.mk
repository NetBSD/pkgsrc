# $NetBSD: omf.mk,v 1.7 2004/04/27 01:26:29 wiz Exp $
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

. include "../../mk/bsd.prefs.mk"

# scrollkeeper's data directory.
SCROLLKEEPER_DATADIR=	${BUILDLINK_PREFIX.scrollkeeper}/libdata/scrollkeeper

# scrollkeeper binary programs.
SCROLLKEEPER_REBUILDDB=	${BUILDLINK_PREFIX.scrollkeeper}/bin/scrollkeeper-rebuilddb
SCROLLKEEPER_UPDATEDB=	${BUILDLINK_PREFIX.scrollkeeper}/bin/scrollkeeper-update

USE_PKGINSTALL=		YES
INSTALL_EXTRA_TMPL+=	${.CURDIR}/../../textproc/scrollkeeper/files/install.tmpl
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/../../textproc/scrollkeeper/files/install.tmpl

FILES_SUBST+=		SCROLLKEEPER_DATADIR="${SCROLLKEEPER_DATADIR}"
FILES_SUBST+=		SCROLLKEEPER_REBUILDDB="${SCROLLKEEPER_REBUILDDB}"
FILES_SUBST+=		SCROLLKEEPER_UPDATEDB="${SCROLLKEEPER_UPDATEDB}"

PRINT_PLIST_AWK+=	/^libdata\/scrollkeeper/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm libdata\/scrollkeeper/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/omf$$/ \
				{ print "@comment in scrollkeeper: " $$0; \
				  next; }

.if !defined(NO_BUILDLINK)
.  if !empty(USE_BUILDLINK3:M[yY][eE][sS])
.    include "../../textproc/scrollkeeper/buildlink3.mk"
.  endif
.endif

.endif	# SCROLLKEEPER_OMF_MK
