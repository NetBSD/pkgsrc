# $NetBSD: Makefile,v 1.42 2018/08/22 09:47:57 wiz Exp $

DISTNAME=	libapreq2-2.13
PKGNAME=	p5-${APACHE_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_APACHE:=httpd/libapreq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/apreq/
COMMENT=	Lots of Apache specific httpd handling modules
LICENSE=	apache-2.0

DEPENDS+=	p5-ExtUtils-XSBuilder>=0.23:../../devel/p5-ExtUtils-XSBuilder

USE_TOOLS+=	gmake
USE_LIBTOOL=	YES
PERL5_PACKLIST=	auto/libapreq2/.packlist

SUBST_CLASSES+=		apxs
SUBST_STAGE.apxs=	pre-configure
SUBST_FILES.apxs=	env/Makefile.in
SUBST_SED.apxs=		-e "s|@APACHE2_APXS@ -i -a -n|@APACHE2_APXS@ -i -n|g"
SUBST_MESSAGE.apxs=	Fixing module installation.

.include "../../lang/perl5/module.mk"

MAKE_PARAMS:=	${MAKE_PARAMS:NINSTALLDIRS=vendor}
MAKE_PARAMS+=	--with-apache2-apxs="${APXS}" --with-mm-opts="INSTALLDIRS=vendor"

pre-configure:
	${LN} -fs ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}
	${LN} -fs ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}

#pre-configure:
#	cd ${WRKSRC} && ./buildconf

.include "../../www/ap2-perl/buildlink3.mk"
.include "../../mk/apache.mk"

BUILDLINK_API_DEPENDS.ap2-perl+=	${APACHE_PKG_PREFIX}-perl>=2.0.1
BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.48
.include "../../mk/bsd.pkg.mk"
