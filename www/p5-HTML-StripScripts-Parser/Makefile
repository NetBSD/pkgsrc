# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:42 joerg Exp $

DISTNAME=	HTML-StripScripts-Parser-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-HTML-StripScripts-Parser/
COMMENT=	Perl5 module XSS filter using HTML::Parser

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+= 	p5-HTML-StripScripts>=1.04:../../www/p5-HTML-StripScripts

PERL5_PACKLIST=	auto/HTML/StripScripts/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
