# $NetBSD: Makefile,v 1.13 2006/01/24 07:32:49 wiz Exp $

DISTNAME=	Apache-SSI-2.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5ass
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to implement Server Side Includes

DEPENDS+=	p5-HTML-SimpleParse>=0.06:../../www/p5-HTML-SimpleParse

PERL5_PACKLIST=		auto/Apache/SSI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
