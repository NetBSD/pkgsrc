# $NetBSD: Makefile,v 1.7 2011/08/14 16:05:43 obache Exp $
#

DISTNAME=	Apache2-AuthCookieDBI-2.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache2-AuthCookieDBI
COMMENT=	Perl5 module AuthCookie backed by a DBI database
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Apache2-AuthCookie>=3.08:../../www/p5-Apache2-AuthCookie
DEPENDS+=	p5-Apache-DBI>=0.91:../../databases/p5-Apache-DBI
DEPENDS+=	p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc

CONFLICTS+=	p5-Apache-AuthCookieDBI-[0-9]*

PERL5_PACKLIST=		auto/Apache2/AuthCookieDBI/.packlist

.include "../../www/ap2-perl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
