# $NetBSD: Makefile,v 1.25 2024/05/12 16:26:16 taca Exp $

DISTNAME=	aws-sdk-s3-1.149.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-sdk-ruby
COMMENT=	AWS SDK for Ruby - Amazon S3
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-aws-sdk-kms>=1<2:../../www/ruby-aws-sdk-kms
#DEPENDS+=	${RUBY_PKGPREFIX}-aws-sdk-core>=3.194<4:../../www/ruby-aws-sdk-core
#DEPENDS+=	${RUBY_PKGPREFIX}-aws-sigv4>=1.8<2:../../www/ruby-aws-sigv4

USE_LANGUAGES=		# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
