# $NetBSD: Makefile,v 1.6 2003/12/03 22:14:46 kristerw Exp $

DISTNAME=	libapreq-1.2
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lap
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/apreq/
COMMENT=	Lots of Apache specific httpd handling modules

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/libapreq/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
