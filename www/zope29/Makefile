# $NetBSD: Makefile,v 1.7.4.1 2007/03/22 14:45:45 ghen Exp $
# FreeBSD Id: ports/www/zope29/Makefile,v 1.86 2006/08/03 15:53:04 garga Exp

DISTNAME=	Zope-${VER}-final
PKGNAME=	zope-${VER}
PKGREVISION=	4
CATEGORIES=	www python
MASTER_SITES=	http://www.zope.org/Products/Zope/${VER}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/
COMMENT=	Zope, the Z Object Publishing Environment

DEPENDS+=	${PYPKGPREFIX}-xml-[0-9]*:../../textproc/py-xml

PYTHON_VERSIONS_ACCEPTED=   24
RCD_SCRIPTS=	${PKGBASE}29 zeo29

VER=		2.9.4
DIST_SUBDIR=	${PKGBASE}29-20070321
HOTFIXES=	Hotfix_20070320

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.for f in ${HOTFIXES}
DISTFILES+=		${f}.tgz
SITES.${f}.tgz= \
	http://www.zope.org/Products/Zope/Hotfix-2007-03-20/Hotfix-20070320/
.endfor

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
MAKE_FILE=	makefile

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
.for d in ${HOTFIXES}
	cd ${WRKDIR}; ${PAX} -rw ${d} ${ZOPEBASEDIR}/lib/python/Products
.endfor
	${FIND} ${ZOPEBASEDIR} -type f -print0 | ${XARGS} -0 -- ${CHMOD} a-w

pre-package:
	${CP} ${WRKDIR}/package-pkg-message ${PKGMESSAGE}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
