# $NetBSD: Makefile,v 1.45 2006/08/15 12:10:52 abs Exp $

DISTNAME=	libwww-perl-5.805
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
PKGREVISION=	1
SVR4_PKGNAME=	p5lww
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/libwww-perl/
COMMENT=	Perl5 library for WWW access

DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-Crypt-SSLeay>=0:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-HTML-Parser>=3.33:../../www/p5-HTML-Parser
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-MIME-Base64>=2.1:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Net>=1.09:../../net/p5-Net		# for Net::FTP>=2.58
DEPENDS+=	p5-URI>=1.10:../../www/p5-URI
DEPENDS+= 	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/LWP/.packlist
MAKE_PARAMS=		-n

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
