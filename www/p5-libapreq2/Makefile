# $NetBSD: Makefile,v 1.3 2004/10/03 00:18:27 tv Exp $

DISTNAME=	libapreq2-2.02_02-dev
PKGNAME=	p5-libapreq2-2.2.2
PKGREVISION=	1
SVR4_PKGNAME=	p5la2
CATEGORIES=	www perl5
MASTER_SITES=	http://www.apache.org/dist/httpd/libapreq/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/apreq/
COMMENT=	Lots of Apache specific httpd handling modules

DEPENDS+=	ap2-perl-[0-9]*:../../www/ap2-perl
DEPENDS+=	p5-ExtUtils-XSBuilder-[0-9]*:../../www/p5-ExtUtils-XSBuilder

WRKSRC=		${WRKDIR}/libapreq2-2.02-dev
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/libapreq2/.packlist

MAKE_PARAMS+=	--with-apache2-apxs="${APXS}"

#pre-configure:
#	cd ${WRKSRC} && ./buildconf

.include "../../lang/perl5/module.mk"
#.include "../../www/ap2-perl/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
