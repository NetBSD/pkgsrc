# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:42 joerg Exp $

DISTNAME=	HTML-StripScripts-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-StripScripts/
COMMENT=	Perl5 module to strip scripting constructs out of HTML

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/HTML/StripScripts/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
