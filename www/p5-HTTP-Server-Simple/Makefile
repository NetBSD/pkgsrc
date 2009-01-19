# $NetBSD: Makefile,v 1.12 2009/01/19 22:16:19 seb Exp $
#

DISTNAME=	HTTP-Server-Simple-0.38
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hss
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-Simple/
COMMENT=	Perl5 module providing a simple standalone HTTP daemon

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=		auto/HTTP/Server/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
