# $NetBSD: Makefile,v 1.6 2011/08/14 16:05:59 obache Exp $

DISTNAME=	HTTP-Server-Simple-Static-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-Simple-Static/
COMMENT=	Serve static files with HTTP::Server::Simple

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTTP/Server/Simple/Static/.packlist

DEPENDS+=	p5-File-MMagic-[0-9]*:../../misc/p5-File-MMagic
DEPENDS+=	p5-HTTP-Server-Simple>=0.01:../../www/p5-HTTP-Server-Simple
DEPENDS+=	p5-MIME-Types-[0-9]*:../../mail/p5-MIME-Types
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
