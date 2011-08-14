# $NetBSD: Makefile,v 1.6 2011/08/14 16:06:02 obache Exp $

DISTNAME=	Kwiki-Simple-Server-HTTP-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Kwiki-Simple-Server-HTTP/
COMMENT=	Kwiki plugin to start a standalone Kwiki HTTP server

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-HTTP-Server-Simple-Kwiki-[0-9]*:../../www/p5-HTTP-Server-Simple-Kwiki
DEPENDS+=	p5-Kwiki>=0.37:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Simple/Server/HTTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
