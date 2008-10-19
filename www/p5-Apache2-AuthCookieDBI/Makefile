# $NetBSD: Makefile,v 1.3 2008/10/19 19:19:06 he Exp $
#

DISTNAME=	Apache2-AuthCookieDBI-2.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache2-AuthCookieDBI
COMMENT=	Perl5 module AuthCookie backed by a DBI database

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Apache2-AuthCookie>=3.08:../../www/p5-Apache2-AuthCookie
DEPENDS+=	p5-Apache-DBI>=0.91:../../databases/p5-Apache-DBI
DEPENDS+=	p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

CONFLICTS+=	p5-Apache-AuthCookieDBI-[0-9]*

PERL5_PACKLIST=		auto/Apache2/AuthCookieDBI/.packlist

.include "../../www/ap2-perl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
