# $NetBSD: Makefile,v 1.15 2006/10/17 12:58:26 obache Exp $
#

DISTNAME=	Apache-AuthCookie-3.10
PKGNAME=	p5-${DISTNAME}
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
