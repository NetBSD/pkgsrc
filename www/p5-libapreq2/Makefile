# $NetBSD: Makefile,v 1.9 2005/07/13 18:01:48 jlam Exp $

DISTNAME=	libapreq2-2.04_03-dev
PKGNAME=	p5-libapreq2-2.4.3
SVR4_PKGNAME=	p5la2
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	http://www.apache.org/dist/httpd/libapreq/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/apreq/
COMMENT=	Lots of Apache specific httpd handling modules

DEPENDS+=	p5-ExtUtils-XSBuilder>=0.23:../../devel/p5-ExtUtils-XSBuilder

BUILDLINK_DEPENDS.apache+=	apache>=2.0.48
BUILDLINK_DEPENDS.ap2-perl+=	ap2-perl>=1.99.15

WRKSRC=		${WRKDIR}/libapreq2-2.04-dev
USE_TOOLS+=	gmake
USE_LIBTOOL=	YES
PERL5_PACKLIST=	auto/libapreq2/.packlist
PERL5_REQD+=	5.6.1

SUBST_CLASSES+=		apxs
SUBST_STAGE.apxs=	post-patch
SUBST_FILES.apxs=	env/Makefile.in
SUBST_SED.apxs=		-e "s|@APACHE2_APXS@ -i -a -n|@APACHE2_APXS@ -i -n|g"
SUBST_MESSAGE.apxs=	"Fixing module installation."

MAKE_PARAMS+=	--with-apache2-apxs="${APXS}"

#pre-configure:
#	cd ${WRKSRC} && ./buildconf

.include "../../lang/perl5/module.mk"
.include "../../www/ap2-perl/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
