# $NetBSD: Makefile,v 1.22 2012/10/28 06:30:25 asau Exp $
#

DISTNAME=	Apache-AuthCookie-3.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache-AuthCookie/
COMMENT=	Perl5 module for Authentication and Authorization via cookies

DEPENDS+=	ap13-perl>=1.29:../../www/ap-perl
DEPENDS+=	p5-Apache-Test-[0-9]*:../../www/p5-Apache-Test

PERL5_PACKLIST=		auto/Apache/AuthCookie/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
