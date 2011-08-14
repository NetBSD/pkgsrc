# $NetBSD: Makefile,v 1.6 2011/08/14 16:05:58 obache Exp $

DISTNAME=	HTTP-Server-Simple-Kwiki-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-Simple-Kwiki/
COMMENT=	standalone HTTP server for Kwiki

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTTP/Server/Simple/Kwiki/.packlist

DEPENDS+=	p5-HTTP-Server-Simple-Static-[0-9]*:../../www/p5-HTTP-Server-Simple-Static
DEPENDS+=	p5-IO-Capture-[0-9]*:../../devel/p5-IO-Capture
DEPENDS+=	p5-Kwiki-[0-9]*:../../www/p5-Kwiki

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
