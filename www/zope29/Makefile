# $NetBSD: Makefile,v 1.4 2006/09/07 16:14:16 taca Exp $
# FreeBSD Id: ports/www/zope29/Makefile,v 1.86 2006/08/03 15:53:04 garga Exp

DISTNAME=	Zope-2.9.4-final
PKGNAME=	zope-2.9.4
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.zope.org/Products/Zope/${PKGVERSION}/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	zope

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/
COMMENT=	Zope, the Z Object Publishing Environment

DEPENDS+=	${PYPKGPREFIX}-xml-[0-9]*:../../textproc/py-xml

DIST_SUBDIR=    zope
PYTHON_VERSIONS_ACCEPTED=   24
RCD_SCRIPTS=	${PKGBASE}29.sh zeo29.sh

# Change these, if you like, via the environment.
ZOPE_USER?=		www
WEBBASEDIR?=		www
SZOPEBASEDIR?=		${WEBBASEDIR}/Zope29

# Do not change anything below this line.

.if defined(INSTANCENAME)
ZOPEINSTANCENAME=	${INSTANCENAME}
.endif

ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEINSTANCEBASE?=	${PREFIX}/${SZOPEBASEDIR}
ZOPEINSTANCEDIR?=	${ZOPEINSTANCEBASE}/${ZOPEINSTANCENAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${ZOPEBASEDIR} --with-python=${PYTHONBIN}

BUILD_TARGET=	build
MAKEFILE=	makefile

PLIST_SUBST=	ZOPEBASEDIR=${SZOPEBASEDIR}
MESSAGE_SUBST+=	ZOPEBASEDIR=${ZOPEBASEDIR}
MESSAGE_SUBST+=	ZOPE_USER=${ZOPE_USER} \
MESSAGE_SUBST+=	ZOPEINSTANCEDIR=${ZOPEINSTANCEDIR}

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -print0 | ${XARGS} -0 -- ${RM}

post-install:
	${MV} ${ZOPEBASEDIR}/skel/etc/zope.conf.in \
		${ZOPEBASEDIR}/skel/etc/zope.conf.sample.in

	${MKDIR} ${ZOPEBASEDIR}/Products

	${FIND} ${ZOPEBASEDIR} -type f -print0 | ${XARGS} -0 -- ${CHMOD} a-w

pre-package:
	${CP} ${WRKDIR}/package-pkg-message ${PKGMESSAGE}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
