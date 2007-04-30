# $NetBSD: Makefile,v 1.15 2007/04/30 21:49:04 heinz Exp $

DISTNAME=	XML-NamespaceSupport-1.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-NamespaceSupport/
COMMENT=	Perl module to the SAX2 NamespaceSupport class

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/XML/NamespaceSupport/.packlist

post-extract:
	${CHMOD} a-x ${WRKSRC}/NamespaceSupport.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
