# $NetBSD: Makefile,v 1.3 2009/05/21 14:28:45 tonnerre Exp $

DISTNAME=	HTML-RewriteAttributes-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-p5-people@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-RewriteAttributes/
COMMENT=	Perl module for concise attribute rewriting

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tagset-[0-9]*:../../www/p5-HTML-Tagset
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=	auto/HTML/RewriteAttributes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
