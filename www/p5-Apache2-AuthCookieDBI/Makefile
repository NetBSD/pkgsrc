# $NetBSD: Makefile,v 1.1.1.1 2008/06/20 14:16:42 he Exp $
#

DISTNAME=	Apache2-AuthCookieDBI-2.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache2-AuthCookieDBI
COMMENT=	Perl5 module AuthCookie backed by a DBI database

DEPENDS+=	p5-Apache2-AuthCookie>=3.08:../../www/p5-Apache2-AuthCookie
DEPENDS+=	p5-Apache-DBI>=0.91:../../databases/p5-Apache-DBI
DEPENDS+=	p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

CONFLICTS+=	p5-Apache-AuthCookieDBI-[0-9]*

PERL5_PACKLIST=		auto/Apache2/AuthCookieDBI/.packlist

.include "../../www/ap2-perl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
