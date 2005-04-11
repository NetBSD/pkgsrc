# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:55 tv Exp $

DISTNAME=	Apache-SSI-2.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ass
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to implement Server Side Includes

DEPENDS+=	p5-HTML-SimpleParse>=0.06:../../www/p5-HTML-SimpleParse

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/SSI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
