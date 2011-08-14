# $NetBSD: Makefile,v 1.15 2011/08/14 16:05:41 obache Exp $
#

DISTNAME=	Apache-AuthCookieDBI-2.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~cromis/Apache-AuthCookieDBI-1.19/
COMMENT=	Perl5 module AuthCookie backed by a DBI database

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Apache-AuthCookie-[0-9]*:../../www/p5-Apache-AuthCookie
DEPENDS+=	p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Apache-DBI-[0-9]*:../../databases/p5-Apache-DBI
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI

PERL5_PACKLIST=		auto/Apache/AuthCookieDBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
