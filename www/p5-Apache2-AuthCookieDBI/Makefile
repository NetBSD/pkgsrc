# $NetBSD: Makefile,v 1.20 2019/08/11 13:24:24 wiz Exp $
#

DISTNAME=	Apache2-AuthCookieDBI-2.17
PKGREVISION=	6
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Apache2-AuthCookieDBI
COMMENT=	Perl5 module AuthCookie backed by a DBI database
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	p5-Apache2-AuthCookie>=3.08:../../www/p5-Apache2-AuthCookie
DEPENDS+=	p5-DBI>=1.40:../../databases/p5-DBI
DEPENDS+=	p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc

CONFLICTS+=	p5-Apache-AuthCookieDBI-[0-9]*

PERL5_PACKLIST=		auto/Apache2/AuthCookieDBI/.packlist

.include "../../www/ap2-perl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
