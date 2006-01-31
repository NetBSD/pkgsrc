# $NetBSD: Makefile,v 1.1.1.1 2006/01/31 21:39:20 jschauma Exp $

DISTNAME=      	Kwiki-Weather-0.05
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Weather button and WAFL for your Kwiki

DEPENDS+=	p5-Kwiki>=0.34:../../www/p5-Kwiki
DEPENDS+=	p5-Geo-Weather>=1.41:../../misc/p5-Geo-Weather
DEPENDS+=	p5-Kwiki-Zipcode>=0.12:../../www/p5-Kwiki-Zipcode

PERL5_PACKLIST=		auto/Kwiki/Weather/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
