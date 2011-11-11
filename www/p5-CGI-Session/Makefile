# $NetBSD: Makefile,v 1.18 2011/11/11 08:28:38 hiramatsu Exp $

DISTNAME=		CGI-Session-4.48
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ses
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Session/
COMMENT=		Perl5 module providing session management across HTTP requests
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews
PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		auto/CGI/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
