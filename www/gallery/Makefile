# $NetBSD: Makefile,v 1.16 2018/08/22 09:47:25 wiz Exp $
#

DISTNAME=	gallery-1.5.10
PKGREVISION=	10
CATEGORIES=	www graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gallery/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://gallery.sourceforge.net/
COMMENT=	Web-based photo gallery written in PHP
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.1.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=4.1.0:../../devel/php-gettext

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	perl:run

REPLACE_PERL=	po/remove_obsolete.pl po/transform_fuzzy.pl
REPLACE_SH=	po/create_po_template.sh po/change_version.sh
REPLACE_SH+=	po/edit_changelog.sh po/make_mo_files.sh
REPLACE_SH+=	po/update_po_files.sh

PKG_SYSCONFDIR=	${G1DIR}

EGDIR=		${PREFIX}/share/examples/gallery
G1DIR=		${PREFIX}/share/gallery

CONF_FILES_PERMS=	${EGDIR}/config.php ${G1DIR}/config.php \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0666
CONF_FILES_PERMS+=	${EGDIR}/.htaccess ${G1DIR}/.htaccess \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0666

MESSAGE_SUBST+=	G1DIR=${G1DIR}
FILES_SUBST+=	G1DIR=${G1DIR}

SUBST_CLASSES+=	paths
SUBST_FILES.paths=	${WRKDIR}/gallery.conf
SUBST_VARS.paths+=	G1DIR
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS=	share/examples/gallery
INSTALLATION_DIRS+=	share/gallery

post-extract:
	${CP} ${FILESDIR}/gallery.conf ${WRKDIR}/
	${TOUCH} ${WRKDIR}/config.php
	${TOUCH} ${WRKDIR}/.htaccess

do-install:
	${INSTALL_DATA} ${WRKDIR}/gallery.conf ${DESTDIR}${EGDIR}/gallery.conf
	${INSTALL_DATA} ${WRKDIR}/config.php ${DESTDIR}${EGDIR}/config.php
	${INSTALL_DATA} ${WRKDIR}/.htaccess ${DESTDIR}${EGDIR}/.htaccess
	${CP} -R ${WRKSRC}/* ${DESTDIR}${G1DIR}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
