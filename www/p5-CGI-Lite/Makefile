# $NetBSD: Makefile,v 1.17 2018/08/22 09:47:30 wiz Exp $

DISTNAME=		CGI-Lite-3.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		bad@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Lite/
COMMENT=		Simple perl5 module for writing forms-based CGI programs
LICENSE=		${PERL5_LICENSE}

PREV_PKGPATH=		www/p5-CGI_Lite
SUPERSEDES=		p5-CGI_Lite-[0-9]*

PERL5_PACKLIST=		auto/CGI/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
